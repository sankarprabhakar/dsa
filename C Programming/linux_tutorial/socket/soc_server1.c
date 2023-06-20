/*
 * soc_server1.c
 *
 *  Created on: Jul 29, 2016
 *      Author: sankarsa
 */
#include<arpa/inet.h>
#include<sys/socket.h>
//#include<sys/types.h>
#include<stdio.h>

void main(int argc , char *argv[])
{
	if(argc < 3)
	{
		return;
	}
	int sfd = socket(AF_INET, SOCK_STREAM, 0); // TCP socket...
	if(sfd < 0)
	{
		perror("Socket creation failed");
		return;
	}

	/*binding the ip address*/
	struct sockaddr_in s_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&s_addr.sin_addr); //This will convert string to decimal(host bit order)

	int ret = bind(sfd, (struct sockaddr *)&s_addr, sizeof(struct sockaddr_in));
	if(ret < 0)
	{
		perror("Binding failed");
		return;
	}

	/*Make the port passive using listen call*/
	ret = listen(sfd, 1);
	if(ret < 0)
	{
		perror("Listen failed");
		return;
	}

	/*Accept incoming connection*/
	struct sockaddr cliaddr;

	while(1)
	{
		printf("Waiting for accept %d\n",getpid());
		int len = sizeof(struct sockaddr);
		int cfd  = accept(sfd,&cliaddr, &len );
		if(cfd < 0)
		{
			perror("Accept failed");
			return;
		}
		int ch = fork();
		if(ch == 0)
		{




			printf("From child\n");
			char buffer[1024];




			/*We wanted to get port number and address of server and client*/
					 len = sizeof(struct sockaddr_in);
					struct sockaddr_in server;
					ret = getsockname(sfd, (struct sockaddr *)&server, &len);
					if(ret < 0)
					{
						perror("GET1 sock name");
						return;
					}
					int len1 = sizeof(struct sockaddr_in);
					struct sockaddr_in client;
					ret = getpeername(cfd, (struct sockaddr *)&client, &len1);
					if(ret < 0)
					{
						perror("GET2 sock name");
						return;
					}

					printf("Server details :\n");
					printf("Server IP Address : %s\n", inet_ntop(AF_INET,&(((struct sockaddr_in *)&server)->sin_addr), &buffer[0], 1024));
					printf("Server Port : %d\n", htons(((struct sockaddr_in *)&server)->sin_port));
					printf("Client IP Address : %s\n", inet_ntop(AF_INET,&(((struct sockaddr_in *)&client)->sin_addr), &buffer[0], 1024));
					printf("Client Port : %d\n", htons(((struct sockaddr_in *)&client)->sin_port));




			ret  = read(cfd, &buffer,1024);
			if(ret < 0)
			{
				perror("Read failed");
				return;
			}
			buffer[ret] = '\0';
			printf("Message is %s \n", buffer);
			buffer[ret] = ':';
			ret++;


			inet_ntop(AF_INET, &(((struct sockaddr_in *)&cliaddr)->sin_addr), &buffer[ret], 1024 );
			int len = strlen(buffer);

			ret  = write(cfd, &buffer,len);
			if(ret < 0)
			{
				perror("Read failed");
				return;
			}
			//buffer[ret] = '\0';
			printf("Message is %s \n", buffer);









			close(cfd);
			close(sfd);//we dont need the sfd in child
			return;
			//while(1);
		}

	}
}

