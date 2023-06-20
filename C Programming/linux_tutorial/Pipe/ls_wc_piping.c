/*
 * ls_wc_piping.c
 *
 *  Created on: Jul 5, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<unistd.h>

void main(int argc, char *argv[])
{

	printf("hello world\n");

	int fd[2];
	int buffer[100];
	int ret = pipe(fd);
	if(ret < 0)
	{
		perror("PIPE");
	}

	int cpid = fork();
	if(cpid < 0)
	{
		return;
	}
	else if(cpid == 0)
	{
			close(1);//close stdout.
			close(fd[0]); //read end is closed
			dup(fd[1]); //write end is duplicated

			execlp("ls","ls",NULL);

	}
	else
	{
			close(0);
			close(fd[1]);
			dup(fd[0]);
			wait();
			execlp("wc","wc", NULL);



	}








}


