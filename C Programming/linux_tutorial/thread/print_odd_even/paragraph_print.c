#include <stdio.h>
#include <semaphore.h>

sem_t sems[500];
void * print_word(void *tinfo);

FILE *fp = NULL;

struct thread_info
{
int tid;
int num;	
};
struct thread_info tinfo[500];
int main(int arg, char * argc[])
{
	
	pthread_t t[500];
	int i = 0;
	int max = 0;
	printf("ARG = %d %s %s \n", arg, argc[0], argc[1]) ;
	if(arg == 2)
	 max = atoi(argc[1]);
	
	
	
	for(i = 0; i< max; i++)
	{
		sem_init(&sems[i], 0 , 1);
		sem_wait(&sems[i]);
		tinfo[i].tid = i;
		tinfo[i].num = max;
		pthread_create(&t[i],NULL,&print_word, (void *)&tinfo[i]);	
	}
	
	sem_post(&sems[0]);
	
	while(1)
		;
	
	
}


void * print_word(void *t)
{
	struct thread_info *tinfo = (struct thread_info *)t;
	int tid = tinfo->tid;
	int num = tinfo->num;
	int next = 0;
	char str[100];
	int status = 0;
	printf("Tid - %d\n", tid);
	
	
	while(1)
	{
	sem_wait(&sems[tid]);
	
	if(fp == NULL)
	{
		fp = fopen("para.txt","r");
		
	}
	
	int f = fscanf(fp,"%s", &str);
	if(f == EOF)
	{
		exit(0);
	}
	
	printf("%d - %s \n",tid, str);
	
	next = (tid + 1)%num;
	sem_post(&sems[next]);
	}
	
	
}





