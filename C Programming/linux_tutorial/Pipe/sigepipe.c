/*
 * sigepipe.c
 *
 *  Created on: Jul 5, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<limits.h>

void epipe(int sig)
{
	printf("Sig pipe is detected\n");
}
char buffer[65*1024];
void main(int argc, char *argv[])
{
	printf("Hello world Pipe buffer = %d\n",PIPE_BUF);

	int fd[2];



	signal(SIGPIPE, epipe);

	int ret = pipe(fd);
	if(ret < 0)
	{
		perror("Pipe failed");
	}
	close(fd[0]); //close the read end..
	ret = write(fd[1],"Hello from child",16);
	if(ret < 0)
	{
		perror("Write Error");
	}

//	close(fd[0]); //close the read end..
//		ret = write(fd[1],buffer,65*1024);
//		if(ret < 0)
//		{
//			perror("Write Error");
//		}





}
