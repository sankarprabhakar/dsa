/*
 * posix_msgq_server1.c
 *
 *  Created on: Jul 15, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<mqueue.h>
#include<sys/stat.h>
#include<fcntl.h>


void main(int argc, char*argv[])
{
	printf("Hello world\n");

	mqd_t ms = mq_open("/queue1", O_CREAT | O_RDWR, S_IRWXU, NULL);
	if(ms < 0)
	{
		perror("MQ OPEN FAILED");
	}
	char buf[9000];
	int pri = 0;
	int size =	mq_receive(ms, buf, 9000, &pri); //This call will wait till there is a message availble
	if(size < 0)
	{
		perror("Error in receive");
		return ;
	}
	printf("size = %d \n", size);
	printf("priority = %d \n", pri);
	printf("data = %s \n", buf);


	/*delete the queue*/

	int ret = mq_unlink("/queue1");
	if(ret < 0)
	{
		perror("Deletion of queue failed");
	}




}
