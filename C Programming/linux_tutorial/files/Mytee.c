/*
 * Mytee.c
 *
 *  Created on: Jun 24, 2016
 *      Author: sankarsa
 */


#include<stdio.h>

#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


/*
 * 1. read from 0
 * 2. Write to 1 and opened file
 * */

void main(int argc, char *argv[])
{

	char buffer[1024] = {0};
	int act_read = 0;
	int act_write_buffer = 0;
	int act_write = 0;
	char *buf = buffer;


	int filefd = open(argv[1],O_CREAT| O_RDWR);
	if(filefd < 0)
	{
		perror("Open failed");
	}
	while(1)
	{
		buf = buffer;
		/*read the input*/
		act_read = read(0, buffer, 1);
		act_write_buffer = act_read;
		while(act_write_buffer > 0)
		{
			act_write = write(1, buf, act_write_buffer);
			act_write_buffer -= act_write;
			buf += act_write;
		}

		act_write_buffer = act_read;
		buf = buffer;

		while(act_write_buffer > 0)
		{
			act_write = write(filefd, buf, act_write_buffer);
			act_write_buffer -= act_write;
			buf += act_write;
		}

	}

}

