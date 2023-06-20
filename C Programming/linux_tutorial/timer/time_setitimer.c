#include<stdio.h>
#include<sys/signal.h>
#include<sys/time.h>
int sec = 10;

void sigalarm(int sig)
{
 sec = sec+1;
 printf("Sec = %d\n",sec);
}

void main()
{

signal(SIGALRM, sigalarm);

struct itimerval new,old;

new.it_interval.tv_sec = 1;
new.it_interval.tv_usec = 0;
new.it_value.tv_sec=10;
new.it_value.tv_usec=0;

setitimer(ITIMER_REAL,&new,&old);


while(1)
;
printf("PSS - Ending program\n");
}
