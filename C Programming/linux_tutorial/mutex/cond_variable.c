#include<stdio.h>
#include<pthread.h>
//#include<mutex.h>

void * fun1(void *x);
void * fun2(void *x);



pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;




int counter = 0;
void main()
{
	pthread_t t;
	pthread_create(&t,NULL, fun1, NULL);
//	pthread_detach(t);
	pthread_create(&t,NULL, fun2, NULL);
	//pthread_detach(t);
	while(1)
		;


}
void * fun1(void *x)
{
	for(;;)
	{
		pthread_mutex_lock(&mut);

		pthread_cond_wait( &cond,&mut);
		printf("A\n");

		counter++;
		printf("FUN 1 - %d\n", counter);

	    printf("B\n");
		pthread_mutex_unlock(&mut);
		if(counter >= 10) return NULL;
	}
//return NULL;
}


void * fun2(void *x)
{

	for(;;)
	{
		pthread_mutex_lock(&mut);

		if(counter < 3 || counter > 6)
		{
			pthread_cond_signal(&cond);
			printf("X\n");
		}
		else{

			
		counter++;
		printf("FUN 2 - %d\n", counter);	
	
		}
        printf("Y\n");
		pthread_mutex_unlock(&mut);

		if(counter >= 10) return NULL;
	}
//return NULL;
}


