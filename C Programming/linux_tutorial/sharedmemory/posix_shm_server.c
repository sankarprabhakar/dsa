/*
 * posix_shm_server.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */


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
#include<sys/ipc.h>
#define ERROR_EXIT(x) if(x < 0) { perror("failed"); return;}
/*Client will read from the stdin*/
void main(int agrc, char *argv[])
{

	sem_unlink("/a1");
	perror("1");
	sem_unlink("/a2");
	perror("2");

	sem_t *read_sem = sem_open("/a1", O_CREAT | O_RDWR, S_IRWXU,0);
	perror("SEM");
	if(read_sem == SEM_FAILED)
	{
		printf("Read sem creation failed \n");
		return;
	}
	/*Creating a semaphore - named one!!*/
	sem_t *write_sem = sem_open("/a2", O_CREAT | O_RDWR, S_IRWXU,1);
	perror("SEM");
	if(write_sem == SEM_FAILED)
	{
			printf("Read sem creation failed \n");
			return;
	}

	/*Create shared memory*/
	int shmid = shm_open("/shm1", O_CREAT | O_RDWR , S_IRWXU);
	ERROR_EXIT(shmid)


	/*ftruncate*/

	int ret = ftruncate(shmid, 1024);
	ERROR_EXIT(ret)



	/*memory map it to a address*/
	void *share_addr = mmap(NULL,1024,PROT_READ | PROT_WRITE, MAP_SHARED ,shmid,0); /*addr, len,PROT_READ | PROT_WRITE, MAP_PRIVATE or MAP_SHARED or MAP_ANONYMOUS, fd, offset*/

	while(1)
	{
		sem_wait(read_sem);
		printf("Data = %s \n", (char *)share_addr);
		sem_post(write_sem);
	}

}

