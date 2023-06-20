/*
 * simplefifo.c
 *
 *  Created on: Jul 5, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
void main(int agc, char * argv[])
{
	printf("Hello world \n");
	int ret = mkfifo("/tmp/t1fifo",S_IRWXU);
	if(ret < 0 )
	{
		perror("Fifo failed");
	}

	struct stat s1;
	ret = lstat("/tmp/t1fifo", &s1);
	if(ret < 0)
	{
		perror("STAT Failed");
	}

	if(S_ISFIFO(s1.st_mode))
	{
		printf("FIFO");
	}
	else
	{
		printf("NOT FIFO");
	}

	/*
	 * open read and write end on same process using O_NONBLOCK needs the read end
	 * to be opened first then the write end.. write end then read end results in error
	 *
	 * Without nonblock -> the open call for read blocks till write is opened; and vice versa
	 *
	 * */

	int rfd = open("/tmp/t1fifo",O_RDONLY | O_NONBLOCK);
	if(rfd < 0)
	{
		perror("FIFO open for read failed");
	}

	int wfd = open("/tmp/t1fifo",O_WRONLY | O_NONBLOCK);
	if(wfd < 0)
	{
		perror("FIFO open for write failed");
	}



}
