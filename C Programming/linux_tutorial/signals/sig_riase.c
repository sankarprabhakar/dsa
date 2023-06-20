#include<stdio.h>
#include<signal.h>

void intterup_sig(int sig)
{
printf("Ctrl + C presssed \n");
}

void main()
{
//printf("Hello \n");

	int err = signal(SIGINT,intterup_sig);
	if(err == -1)
	{
		printf("Error \n");
	}
	while(1)
	{
		raise(SIGINT);
		sleep(5);
	}


}
