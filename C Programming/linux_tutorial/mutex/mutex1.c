#include<stdio.h>
#include<pthread.h>
#include<errno.h>
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void * fun1(void *);
void main()
{
	pthread_t t,t1;
	
	pthread_create(&t, NULL, fun1, NULL);
	//pthread_detach(t); //this function call will detach thread t from main thread. After this we cannot wait for this thread using pthread_join call.
//pthread_join(t, &ret); // this function will wait for the thread t to end and get the return status here..
	
	pthread_create(&t1, NULL, fun1, NULL);
	//pthread_detach(t1);
	while(1)
		;
}

void * fun1(void *x)
{
	//printf("Hello\n");

if(EBUSY == pthread_mutex_trylock(&mut))
{
	printf("Not allowed to execute \n");
	pthread_exit(0);
}

//pthread_mutex_lock(&mut);
counter++;
printf("%d\n", counter);
sleep(1);
pthread_mutex_unlock(&mut);

}

