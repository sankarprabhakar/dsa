/*
 * posix_shm_client.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<semaphore.h>
#include<sys/mman.h>

#include<fcntl.h>
#include<sys/stat.h>
#define ERROR_EXIT(x) if(x < 0) { perror("failed"); return;}
/*Client will read from the stdin*/
void main(int agrc, char *argv[])
{


	/*Creating a semaphore - named one!!*/
	sem_t *read_sem = sem_open("/a1",  O_RDWR);
	perror("Er");
	if(read_sem == SEM_FAILED)
	{
		printf("Read sem creation failed \n");
		return;
	}
	sem_t *write_sem = sem_open("/a2", O_RDWR);
	if(write_sem == SEM_FAILED)
	{
			printf("Read sem creation failed \n");
			return;
	}
	/*Create shared memory*/
	int shmid = shm_open("/shm1", O_CREAT | O_RDWR , S_IRWXU);
	ERROR_EXIT(shmid)
	printf("Shmid = %d \n",shmid);

	/*ftruncate*/
	/*memory map it to a address*/
	void *share_addr = mmap(NULL,1024,PROT_READ | PROT_WRITE, MAP_SHARED ,shmid,0);
	/*addr, len,PROT_READ | PROT_WRITE, MAP_PRIVATE or MAP_SHARED or MAP_ANONYMOUS, fd, len*/

	printf("Mapping done");


	while(1)
	{

		sem_wait(write_sem);
		read(0,share_addr, 1024);
		sem_post(read_sem);

	}

}

