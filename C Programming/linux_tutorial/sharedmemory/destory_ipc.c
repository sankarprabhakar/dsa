/*
 * destory_ipc.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<semaphore.h>
#include<sys/mman.h>

#include<fcntl.h>
#include<sys/stat.h>
void main(int argc, char * argv[])
{
	printf("Hello world\n");

	sem_unlink("/semread");
	sem_unlink("/semwrite");
	shm_unlink("/shm1");
}
