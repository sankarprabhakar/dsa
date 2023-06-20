/*
 * posix_read_write.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */




#include<stdio.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>

sem_t *rsem,*wsem;
#define ERROR_EXIT(x) if(x < 0) { perror("failed"); return;}

void main(int argc, char*argv[])
{
	int o = 0;
	if(argc == 1)
	{
	sem_unlink("/sem1");
	sem_unlink("/sem2");
	printf("unlink\n");
	}
	//int ret = sem_init(&rsem, 0, 2);
	rsem = sem_open("/sem1", O_CREAT | O_RDWR,S_IRWXU, 2);

	wsem = sem_open("/sem2", O_CREAT | O_RDWR,S_IRWXU, 1);
	//ERROR_EXIT(ret)
	//ret = sem_init(&wsem, 0, 1);
	//ERROR_EXIT(ret)

	while(1)
	{
		printf("Enter option : 1-R/2-W?\n");
		scanf("\n%c", &o);
		printf("%c\n", o);
		if(o == '1')
		{
			readOp();
		}else if(o == '2')
		{
			writeOp();
		}
	}

}

int readOp()
{
	//take a write semaphore..
	sem_wait(wsem);
	sem_wait(rsem);
	sem_post(wsem);
	printf("Reading \n");
	int o = '7';
	rep:
		scanf("\n%d", &o);
		if(o != 5)
			goto rep;
	//sem_post(&wsem);
	sem_post(rsem);
}

int writeOp()
{
	//take a write semaphore..
	sem_wait(wsem);
	sem_wait(rsem);
	sem_wait(rsem);

	printf("Writing \n");
	int o;

	rep:
	scanf("\n%d", &o);
	if(o != 5)
		goto rep;
	sem_post(wsem);
	sem_post(rsem);
	sem_post(rsem);
}


