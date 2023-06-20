#include<stdio.h>
#include<signal.h>

void intterup_sig(int sig)
{
printf("Ctrl + C presssed \n");
}

void main()
{

	sigset_t block_set, prev_set;
	sigemptyset(&block_set);
	sigaddset(&block_set, SIGINT);

	printf("Is SIGINT set = %d \n",sigismember(&block_set,SIGINT));



	sigprocmask(SIG_BLOCK, NULL, &prev_set);
	perror("SIG PROC");
	printf("SIGINT = %d ", sigismember(&prev_set,SIGINT));


	sigprocmask(SIG_BLOCK, &block_set, &prev_set);

	printf("previous Is SIGINT set = %d \n",sigismember(&prev_set,SIGINT));

	signal(SIGINT,intterup_sig);




	sleep(5);

//raise(SIGINT);
	printf("Sleep over \n");

	if(!sigpending(&prev_set))
	{
		printf("Signal is pening ");
		if(sigismember(&prev_set,SIGINT))
		{
		printf("interrupt signal is pending \n");
		sigprocmask(SIG_UNBLOCK, &block_set, &prev_set);
		}
	}

	printf("2 previous Is SIGINT set = %d \n",sigismember(&prev_set,SIGINT));
	sleep(5);

}
