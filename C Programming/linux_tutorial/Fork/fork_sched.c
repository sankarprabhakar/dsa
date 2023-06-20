/*
 * fork_sched.c
 *
 *  Created on: Jun 29, 2016
 *      Author: sankarsa
 */



#include<stdio.h>
#include<sched.h>
void f1(int *t)
{
	int a;
	printf("P = %lu &a = %lu\n",t,&a);
}

void main(int arc, char *argv[])
{

	struct sched_param x;
	x.sched_priority = 49;
	printf("Hello word\n");
	//daemon(0,0);
	int policy = sched_getscheduler(0);
	printf("Policy =  %d \n", policy);
	sched_setscheduler(0,SCHED_FIFO, &x);

	printf("%d %d %d\n",SCHED_FIFO,SCHED_RR,SCHED_OTHER );


	/*Checking the stack frame...*/
	int a;
	f1(&a);



	while(1)
	{
		;
	}

}
