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
	int ret = 0;

	int c = fork();
	if(c == 0)
	{
		int rfd = open("/tmp/t2wfifo", O_RDONLY);
		if(rfd < 0)
		{
			perror("Pipe open failed");
		}


		int wfd = open("/tmp/t2rfifo", O_WRONLY);
		if(wfd < 0)
		{
			perror("Pipe open failed");
		}


       /*Read from the t2wfifo*/

		char buffer[1024];
		int r = read(rfd, buffer,1024);
		printf("%d bytes read \n", r);
		buffer[r] = '\0';
		printf("Buffer = %s\n", buffer);

		/*Write to t2rfifo*/
		int w = write(wfd, buffer,2);
				printf("%d bytes read \n", w);
			//	buffer[r] = '\0';
				//printf("Buffer = %s\n", buffer);


		ret = unlink("/tmp/t2wfifo");
		if(ret < 0)
		{
			perror("Failed to del fifo");
		}

		ret = unlink("/tmp/t2rfifo");
			if(ret < 0)
			{
				perror("Failed to del fifo");
			}


	}
	else
	{
		printf("This is a parent process\n");
		wait(&ret);
	}

}
