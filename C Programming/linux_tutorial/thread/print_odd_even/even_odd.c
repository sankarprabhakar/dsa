#include <stdio.h>
#include <semaphore.h>

sem_t a,b;
void *f1(void * str);
void *f2(void * str);
void *f3(void * str);
int main()
{
	
	pthread_t t1,t2;
	int s1 = 0;
	int *ret = &s1;
	 sem_init(&a, 0 , 1);
	 sem_init(&b, 0 , 1);
	 
	 /*take both the semaphores*/
	 sem_wait(&a);
	 sem_wait(&b);
	 
	 /*Create two threads*/
	// pthread_create(&t1,NULL, &f1,NULL);
	 
	 //pthread_create(&t2,NULL, &f2,NULL);
	 int thread = 1;
	 pthread_create(&t1,NULL, &f3,(void *)&thread);
	 
	 int thread2 = 2;
	 pthread_create(&t2,NULL, &f3,(void *)&thread2);
	 sem_post(&a); 
	 pthread_join(t1, (void *)&ret);
	 printf("Value at ret = %d \n", *ret);
	 pthread_join(t2, (void *)&ret);
	 printf("Value at ret = %d \n", *ret);
	
	// while(1) //without this line the complete process will exit.. 
	 ;
}
int count = 0;
void *f1(void * str)
{
	static int status = 55;
	
	while(1)
	{
		sem_wait(&a);
		printf("1-%d\n",count);
		count++;
		sleep(2);
		sem_post(&b);
		//pthread_exit((void *)&status);
		//exit(0); //This exit causes all the threads to stop working..
	}
	
	
	
}


void *f2(void * str)
{
	static int status = 55;
	//int count = 1;
	while(1)
	{
		sem_wait(&b);
		printf("2-%d\n",count);
		count++;
		sleep(2);
		sem_post(&a);
		//pthread_exit((void *)&status);
		//exit(0); //This exit causes all the threads to stop working..
	}
	
}


void *f3(void * str)
{
	static int status = 55;
	
	int threadid = *((int *)str);
	printf("thread id = %d \n",threadid);
	//int count = 1;
	while(1)
	{
		if(threadid == 1)
		{
			sem_wait(&a);
		}
		else
		{
			sem_wait(&b);
		}
		printf("%d-%d\n",threadid,count);
		count++;
		sleep(2);
		if(threadid == 1)
		{
			sem_post(&b);
		}
		else
		{
			sem_post(&a);
		}
		//pthread_exit((void *)&status);
		//exit(0); //This exit causes all the threads to stop working..
	}
	
}





