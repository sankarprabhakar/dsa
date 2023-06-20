/*
 * simplepiple.c
 *
 *  Created on: Jul 5, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

void main(int argc, char*argv[])
{
	printf("Hello world\n");

	int fdinfo[2];
	int ret = pipe(fdinfo);
	if(ret < 0)
	{
		perror("PIPE Error");
	}

	printf("Rd  = %d  Wr = %d \n", fdinfo[0],fdinfo[1]);

	struct stat s1, s2;

	ret = fstat(fdinfo[0],&s1);
	if(ret < 0)
	{
		perror("Fstat 0 Error");
	}
	ret = fstat(fdinfo[0],&s2);
	if(ret < 0)
	{
		perror("Fstat 1 Error");
	}

	printf("0 = %x 1 = %x\n",s1.st_mode, s2.st_mode);

	if(S_ISFIFO(s2.st_mode))
	{
		printf("It is a pipe\n");
	}
	char buffer[54];

	/*1 - as read; 0 - as write -- This will not work
	 *
	 * 0 - is always read and 1 - s always write
	 *
	 * */

	ret = fork();
	if(ret == 0)
	{
		printf("Child process \n");
		close(fdinfo[0]); //read end is closed.
		ret = write(fdinfo[1],"Hello from child",16);
		if(ret < 0)
			{
				perror("Write Error");
			}
	}
	else if(ret > 0)
	{
		sleep(10);
		 int len = 54;
		 close(fdinfo[1]);
		 len = read(fdinfo[0], buffer, len);
		 printf("len - %d \n", len);
		 buffer[len] = '\0';
		 printf("Buffer  = %s\n",buffer);
		//read();
	}









}

