#include<stdio.h>
#include<signal.h>

void intterup_sig(int sig)
{
printf("Ctrl + Z presssed \n");
}

void main()
{

	sigset_t block_set, prev_set;
	siginfo_t si;


#if 0
	sigfillset(&block_set);

	//sigaddset(&block_set, SIGINT);

	printf("Is SIGINT set = %d \n",sigismember(&block_set,SIGINT));

	//sigdelset(&block_set, SIGQUIT);
	sigprocmask(SIG_BLOCK, &block_set, &prev_set);

	printf("previous Is SIGINT set = %d \n",sigismember(&prev_set,SIGINT));

	printf("previous Is SIGSTOP set = %d \n",sigismember(&prev_set,SIGSTOP));

	printf("blockset Is SIGSTOP set = %d \n",sigismember(&block_set,SIGSTOP));
	//signal(SIGINT,intterup_sig);

	//printf("2 previous Is SIGINT set = %d \n",sigismember(&prev_set,SIGINT));
	//sleep(5);
	signal(SIGQUIT,intterup_sig);
	sigemptyset(&block_set);

	sigaddset(&block_set, SIGINT);


	int sig = sigwaitinfo(&block_set, &si);
	//int sig = sigismember(&block_set, SIGINT);
	if(sig == SIGINT)
	{
	printf("Int signL \N\N");
	exit(0);
	}
#endif
	//signal(SIGINT,intterup_sig);
	sigfillset(&block_set);

	sigprocmask(SIG_BLOCK, &block_set, &prev_set);
	sigemptyset(&block_set);
	sigaddset(&block_set, SIGINT);
	int sig = sigwaitinfo(&block_set, &si);
	//int sig = sigismember(&block_set, SIGINT);
	if(sig == SIGINT)
	{
	printf("Int signL \N\N");
	exit(0);
	}







//while(1)
//{
//sleep(3);
//}
}
