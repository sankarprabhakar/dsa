/*
 * multiprocess_fifo.c
 *
 *  Created on: Jul 14, 2016
 *      Author: sankarsa
 */


#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

void main(int argc, char *argv[])
{

	int ret = mkfifo("/tmp/t2rfifo", S_IRWXU);
		if(ret < 0)
		{
			perror("Fifo creation failed");
		}
		ret = mkfifo("/tmp/t2wfifo", S_IRWXU);
		if(ret < 0)
		{
			perror("Fifo creation failed");
		}
	int c = fork();
	if(c == 0)
	{
		int wfd = open("/tmp/t2wfifo", O_WRONLY);
		if(wfd < 0)
		{
			perror("Pipe open failed");
		}
		int rfd = open("/tmp/t2rfifo", O_RDONLY);
		if(rfd < 0)
		{
			perror("Pipe open failed");
		}


		int w = write(wfd, "Hi",2);
		printf("%d bytes written \n", w);

		sleep(20);

/*Read from Read fifo*/
		char buffer[1024];
		int r = read(rfd, buffer,1024);
		printf("%d bytes read \n", r);
		buffer[r] = '\0';
		printf("Buffer in FIFO1 = %s\n", buffer);



	}
	else
	{
		printf("This is a parent process\n");
		wait(&ret);
	}

}
