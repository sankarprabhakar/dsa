/*
 * soc_client1.c
 *
 *  Created on: Aug 2, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>


void main(int argc, char * argv[])
{
	if(argc < 3)
	{
		return;
	}
	printf("Addr:%s:%s\n",argv[1],argv[2]);
	int cfd = socket(AF_INET, SOCK_STREAM,0);
	if(cfd < 0)
	{
		perror("Client socket creation failed!!");
		return;
	}

	struct sockaddr_in client;
	client.sin_family = AF_INET;
	client.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&client.sin_addr);

	int ret = connect(cfd, (struct sockaddr *)&client, sizeof(struct sockaddr_in));
	if(ret < 0)
	{
		perror("Connect failed");
		return;
	}

	char buffer[1024] = {'h','e','l','l','o'};

	ret = write(cfd, &buffer,5);
	if(ret <0 )
	{
		perror("Write failed");
		return;
	}
	ret = read(cfd, &buffer, 1024);
	if(ret <0 )
	{
		perror("Write failed");
		return;
	}
	printf("From server %s \n", buffer);
}


