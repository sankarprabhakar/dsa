/*
 * waitfor.c
 *
 *  Created on: Jun 27, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/wait.h>
#include<errno.h>

//extern int errno;

void main(int argc, char*argv[])
{

	int c_pid = fork();
	int ret =0;
	if(c_pid == 0)
	{
		if(*argv[1] == '1')
		{
			printf("Print form child \n");
			exit(100);
		}
		else if (*argv[1] == '2')
		{
			printf("Print form child 2 \n");
			//exit(100);
			int *p = NULL;
			*p = 5;
		}
		else if (*argv[1] == '3')
				{

				printf("SIG STOP called \n");
				raise(SIGSTOP);

				//	printf("Got continue \n");

			}
	}
	else if(c_pid > 0)
	{
		int p  = 0;
		printf("In parent \n");
		do
		{
			p = waitpid(c_pid,&ret,   WUNTRACED | WCONTINUED);
			printf("child pid = %d, ",p);
			perror("Error:");
			if(WIFEXITED(ret))
			{
				printf("Exited normally with status = %d \n",WEXITSTATUS(ret));
			}
			else if(WIFSIGNALED(ret))
			{
				printf("Child has signalled with a signal = %d  \n",WTERMSIG(ret));

			}
			else if(WIFSTOPPED(ret))
			{
				printf("Child has stopped with a signal = %d  \n",WSTOPSIG(ret));
				kill(c_pid,SIGCONT);
											printf("Parent send continue to child \n");


			/*	p = waitpid(c_pid,&ret, WCONTINUED);
				if(WIFEXITED(ret))
				{
						printf("Exited normally with status = %d \n",WEXITSTATUS(ret));
				}*/
			}
			else if(WIFCONTINUED(ret))
			{
				printf("Got signal for continue ret = %d \n", ret);
			}

		}while((!WIFEXITED(ret) && !WIFSIGNALED(ret)));



	}
	else
	{
		printf("fork failed \n");
	}



}
