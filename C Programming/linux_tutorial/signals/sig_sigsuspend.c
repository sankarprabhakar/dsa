#include<stdio.h>
#include<signal.h>

void han(int sig)
{
printf("Sig received = %d",sig);
}
void main()
{

	sigset_t block,pre;
	sigfillset(&block);
	//sigaddset(&block, SIGINT);
	sigprocmask(SIG_BLOCK,&block,&pre);
	sleep(5);
	sigpending(&pre);
	printf("Pending signal SIGINT = %d",sigismember(&pre,SIGINT));


	signal(SIGINT, han);
	//sigemptyset(&block);
	sigdelset(&block, SIGINT);
	/*Suspends till a signal which is not part of block is handled; All other signal should be in "block"
	 * other than  the needed ones.*/
	sigsuspend(&block);
	printf("Some found");

}
