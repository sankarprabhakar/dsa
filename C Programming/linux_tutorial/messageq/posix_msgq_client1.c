/*
 * posix_msgq_client1.c
 *
 *  Created on: Jul 15, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

/*linking using -lrt*/
void main(int agrc, char *argv[])
{
	printf("Hello world\n");

	struct mq_attr s;
//	int ret = 0;

	mqd_t md = mq_open("/queue1", O_CREAT | O_RDWR, S_IRWXU, NULL);
	if(md < 0)
	{
		perror("Message queue opening failed");
	}

	int ret = mq_getattr(md, &s);
	if(ret < 0)
	{
		perror("GET ATTR FAILED");
		return;
	}
	printf("mode flag = %d \n", s.mq_flags);
	printf("max msg  = %d \n", s.mq_maxmsg);
	printf("msg size = %d \n", s.mq_msgsize);
	printf("current msg = %d \n", s.mq_curmsgs);

	char msg[1024] = {'H','E','L','L','O','\0'};

	ret = mq_send(md, &msg, 6, 31);
	if(ret < 0)
	{
		perror("MSG SEND FAILED");
	}




}
