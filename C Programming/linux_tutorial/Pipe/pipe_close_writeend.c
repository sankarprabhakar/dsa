/*
 * pipe_close_writeend.c
 *
 *  Created on: Jul 5, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigpipe(int sig)
{
	printf("Sig pipe\n");
}
void main(int argc, char*argv[])
{
	printf("");
	int fd[2];
	int ret = pipe(fd);
	int buffer[20] = {0};


	/*
	 * SIGPIPE - no read end
	 * EOF - no write end
	 *
	 *
	 * */

	signal(SIGPIPE, sigpipe);

	if(ret<0)
	{
		perror("Pipe failed");
	}

	close(fd[1]);
	ret = read(fd[0],buffer,5);
	if(ret < 0)
	{
		perror("Read pipe failed");
	}
	else
	{
		printf("Read %d \n", ret);
	}




}
