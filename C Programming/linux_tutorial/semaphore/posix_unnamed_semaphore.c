/*
 * posix_unnamed_semaphore.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */

#include<stdio.h>

#include<semaphore.h>
#define ERROR_EXIT(x) if(x < 0) { perror("failed"); return;}
sem_t t;

/*incresing the binary semaphore 3 times and seeing the result*/
void main(int argc, char *argv[])
{
	printf("Hello world\n");

	int ret = sem_init(&t, 0, 1);
	ERROR_EXIT(ret)
	ret = sem_post(&t);
	ERROR_EXIT(ret)
	ret = sem_post(&t);
	ERROR_EXIT(ret)
	int val = 0;
	ret = sem_getvalue(&t, &val);
	ERROR_EXIT(ret)
	printf("val of sem = %d \n", val);


}

