/*
 * programgroup.c
 *
 *  Created on: Jul 4, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(int argc, char*argv[])
{
	printf("Hello world\n");

	printf("PID = %d Group = %d Session id = %d\n",getpid(), getpgrp(), getsid(getpid()));

	//Creating a process group;
	int ret = setpgid(getpid(),getpid());
	if(ret < 0)
	{
		perror("Set pgid failed");
	}

	int i = 0;
	int c = 0;
	while(i < 3)
	{
		i++;
		 c = fork();
		if(c == 0)
		{
			printf("PID = %d PPID = %d PGPID = %d SID = %d \n", getpid(),getppid(), getpgrp(), getsid(getpid()));
			break;
		}
	}

	   if(c != 0)
		{
			ret = setsid(); // Session cannot be starte with program leader group.
			if(ret < 0)
			{
				perror("Session creation failed");
			}

			printf("\nEnd\n");
		}

	while(1)
	{
		if(waitpid(-1, &ret, 0) == -1)
		{
			break;
		}
	}




}


