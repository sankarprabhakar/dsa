/*
 * posix_semaphore_example.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ipc.h>

void main(int argc, char *argv[])
{

	sem_unlink("/tmpsrv1");
	sem_t *sem1 = sem_open("/tmpsrv1", O_CREAT |  O_RDWR, S_IRWXU, 10);
//	printf("SEM_FAILED %d \n", SEM_FAILED);
	perror("SEM");
	if(sem1 == SEM_FAILED)
	{
		printf("error\n");
		perror("Error");
		return;
	}

	while(1)
	{
		//sem_post(sem1);
	int val;
	int ret = sem_getvalue(sem1, &val);
	if(ret < 0)
	{
		perror("SEM GETVAL failed");
		return;
	}
	printf("Val = %d \n", val);
	sem_wait(sem1);
	}


}
