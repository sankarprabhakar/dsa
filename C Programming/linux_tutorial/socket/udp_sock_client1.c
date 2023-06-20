/*
 * udp_sock_client1.c
 *
 *  Created on: Aug 6, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main(int argc, char*argv[])
{


	struct sockaddr_in server,recv_from;

	int cfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(cfd < 0)
	{
		perror("Client socket failed");
		return;
	}

	server.sin_family	=  AF_INET;
	server.sin_port  	=  htons(atoi(argv[2]));

	inet_pton(AF_INET, argv[1], &server.sin_addr);

	char buffer[1024] = {'a','b','c','d','\0'};
	int size = sendto(cfd, buffer, 5, 0, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
	if(size < 0)
	{
		perror("sendto failed");
		return;
	}
	int len = sizeof(struct sockaddr_in);
	size = recvfrom(cfd, buffer,1024, 0,(struct sockaddr*)&recv_from, &len);
	if(size < 0)
	{
		perror("Recv from failed");
		return;
	}

	printf("MSG : %s \n",buffer);




}
