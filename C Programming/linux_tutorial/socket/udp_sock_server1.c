/*
 * udp_sock_server1.c
 *
 *  Created on: Aug 6, 2016
 *      Author: sankarsa
 */
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main(int argc, char *argv[])
{
	struct sockaddr_in server, client;
	if(argc < 3)
	{
		printf("parameters are less than 3\n");
		return;
	}

	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sfd < 0)
	{
		perror("Socket creation failed");
		return;
	}

	/*Bind the address for socket*/
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1], &server.sin_addr);


	int ret = bind(sfd,(struct sockaddr *)&server, sizeof(struct sockaddr_in));
	if(ret < 0)
	{
		perror("Bind failed \n");
		return;
	}

	while(1)
	{
		char buffer[1024];
		struct sockaddr_in recv_from;
		int len = sizeof(struct sockaddr_in);
		int size = recvfrom(sfd,buffer,1024,0 ,(struct sockaddr*)&recv_from,&len ); /*fd, buf, len, flag, sock addr, addr len*/
		if(size < 0)
		{
			perror("Receive error");
			return;
		}
		printf("MSG = %s \n", buffer);

		buffer[0] = 'x';buffer[1] = 'x';buffer[2] = 'A';buffer[3] = '\0';

		size = sendto(sfd,buffer, 4, 0,(struct sockaddr*)&recv_from, sizeof(struct sockaddr_in));
		if(size < 0)
		{
			perror("Send to failed");
			return;
		}


	}







}


