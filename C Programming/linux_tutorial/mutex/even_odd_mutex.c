#include<stdio.h>
#include<pthread.h>


void *eventhread(void *);
void *oddthread(void *);

int counter = 0;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void main()
{
	pthread_t t;
	pthread_create(&t,NULL, eventhread, NULL);
	pthread_create(&t,NULL, oddthread, NULL);
	while(1)
		;

}


void *eventhread(void *x)
{
	while(1)
	{
		pthread_mutex_lock(&mut);
		if(counter % 2 == 0)
		{
			printf("T1 = %d\n",counter);
			counter++;
			sleep(1);
			pthread_cond_signal(&cond);
		}
		else
		{
			pthread_cond_wait(&cond, &mut);
			
		}
		pthread_mutex_unlock(&mut);
	}
	
}

void *oddthread(void *x)
{
	while(1)
	{
		pthread_mutex_lock(&mut);
		if(counter % 2 == 1)
		{
			printf("T2 = %d\n",counter);
			counter++;
			sleep(1);
			pthread_cond_signal(&cond);
		}
		else
		{
			pthread_cond_wait(&cond, &mut);
			
		}
		pthread_mutex_unlock(&mut);
	}
}