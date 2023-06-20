#include<stdio.h>
#include<signal.h>
#include<errno.h>

void intterup_sig(int sig)
{
	printf("Ctrl + C presssed \n");
//	sleep(500);
	//printf("SigINT is done after sleep\n");
	//abort();
}


void intterup_abort(int sig)
{
	printf("abort called \n");
	//abort();
}


void intterup_kill(int sig)
{
	printf("KILL called \n"); //This will never executed as we cannot handle kill signal
	//abort();
}

void intterup_quit(int sig)
{
	printf("Quit called \n"); //This will never executed as we cannot handle kill signal
	//abort();
}


void intterup_stop(int sig)
{
	printf("SIG STOP called \n"); //This will never executed as we cannot handle kill signal
	//abort();

}


void intterup_segv(int sig)
{
	printf("SIGSEGV called \n");
	//abort();
}




void main()
{
//printf("Hello \n");

	int err = signal(SIGINT,intterup_sig);
	if(err == -1)
	{
		printf("Error \n");
	}
	else
	{
		printf("%d \n",err);
	}

	err = signal(SIGINT,intterup_sig);
	if(err == -1)
	{
		printf("Error \n");
	}
	else
	{
		printf("%d \n",err);
	}

	err = signal(SIGABRT,intterup_abort);
		if(err == -1)
		{
			printf("Error \n");
		}
		else
		{
			printf("%d \n",err);
		}


		err = signal(SIGKILL,intterup_kill);//This registration will fail
		if(err == -1)
		{
			printf("Kill Error \n");
			perror("SIGKILL Reg failed");
		}
		else
		{
			printf("%d \n",err);
		}


		err = signal(SIGQUIT,intterup_quit);
				if(err == -1)
				{
					printf("Quit registration Error \n");
				}
				else
				{
					printf("%d \n",err);
				}



				err = signal(SIGSTOP,intterup_stop);//This registration will fail
				if(err == -1)
				{
					printf("SIGSTOP registration Error \n");
					perror("SIGSTOP\n");
				}
				else
				{
					printf("%d \n",err);
				}
				err = signal(SIGSEGV,intterup_segv);
				if(err == -1)
				{
					printf("SIGSEGV registration Error \n");
				}
				else
				{
					printf("%d \n",err);
				}


				/*Setting ignore to segv
				err = signal(SIGINT,SIG_DFL);
				if(err == -1)
				{
					printf("SIGSEGV registration Error \n");
				}
				else
				{
					printf("%d \n",err);
				}*/

				err = signal(SIGTERM,intterup_segv);
				if(err == -1)
				{
					printf("SIGSEGV registration Error \n");
				}
				else
				{
					printf("%d \n",err);
				}






				//exit(0);
				int *p = NULL;
			    //*p = 67;


printf("kill return %d \n ",kill(1, 0));
printf("Errno = %d", errno);

printf("kill return %d \n ",kill(999, 0));
printf("Errno = %d", errno);

while(1)
{
	;
}


}
