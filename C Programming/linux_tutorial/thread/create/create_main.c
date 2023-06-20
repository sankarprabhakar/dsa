#include<stdio.h>
//#include<semaphore.h>
#include<pthread.h>
int f1(void *x);

int main()
{
pthread_t t1, t2;
int pol;
struct sched_param par;
pthread_create(&t1, NULL, &f1, NULL);

while(1)
{
//sleep(1);
// printf("TT\n");
pthread_getschedparam(t1, &pol, &par);

//printf("PSS pol = %d \n",pol);
printf("pol = %d sched = %d SCHED_FIFO %d - SCHED_RR = %d -  idle %d other = %d bath = %d \n",pol ,par.sched_priority,SCHED_FIFO, SCHED_RR,50, SCHED_OTHER,78);

//printf("sched = %d SCHED_FIFO %d - SCHED_RR = %d - %d\n",par.sched_priority,SCHED_FIFO );


}


}


int f1(void *t)
{
printf("Testing .....");
 while(1)
{
	printf("Test -- Thread");
}
}
