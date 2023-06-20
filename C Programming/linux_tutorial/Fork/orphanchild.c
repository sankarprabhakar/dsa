/*
 * orphanchild.c
 *
 *  Created on: Jun 28, 2016
 *      Author: sankarsa
 */



#include<stdio.h>
void main()
{
	int cpid = fork();
	if(cpid > 0)
	{
		exit(0);
	}
	else if(cpid == 0)
	{
		while(1)
		{
			sleep(10);
			printf("%d - %d",getpid(), getppid());
		}
	}
}

