/*
 * popen.c
 *
 *  Created on: Jul 5, 2016
 *      Author: sankarsa
 */


/*
 * 1. open a pipe
 * 2. Execute a command in shell
 * */


#include<stdio.h>
#include<unistd.h>

void main(int arg, char *argv[])
{
	//printf("Hello world\n");


	FILE *fp = popen("ls", "r");
	if(fp == NULL)
	{
		printf("Failed to open file\n");
	}
	char buffer[1024];
	int len = 0;
	//sleep(2);
	//while(len == 0)
	{
	 len = fread(buffer, 1024, 1 ,fp);
	//while( 	fgets(buffer,1024,fp) != NULL);
	{
	//buffer[len] = '\0';
	printf("len = %d \n", len);
	printf("data = %s \n", buffer);
	}
	}
	pclose(fp);


	fp = popen("tee", "w");
	if(fp == NULL)
	{
		printf("Failed to open file\n");
	}
	 buffer[0] = 'h';
//		 ,' ', 'a'};
	 len = 0;
	//sleep(2);
	//while(len == 0)
	{
	 len = fwrite("hello", 5, 1 ,fp);
	//while( 	fgets(buffer,1024,fp) != NULL);
	{
	//buffer[len] = '\0';
//	printf("len = %d \n", len);
	//printf("data = %s \n", buffer);
	}
	}
	pclose(fp);

}
