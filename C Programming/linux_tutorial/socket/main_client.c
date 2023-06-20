#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

#include<sys/socket.h> /*for socket API*/
#include<netinet/in.h>/*for sockaddr_in*/
#include<arpa/inet.h>
#include<errno.h>



#define SERVER_PORT 56
#define SERVER_IP "127.0.0.1"


void main(int argc, char ** argv)
{
	int sockfd = 0;
	struct sockaddr_in sock_addr;
	char message[100] = "Sankar";


	if(argc!=3)
	{
		printf("Number of argument is less than 3..!!!");
		exit(1);
	}
	
   /*creating a socket*/
   sockfd = socket(PF_INET,SOCK_STREAM,0);
   if(sockfd == -1)
   {
	   printf("PSS Error \n");
   }

   /*Format the server address*/
   bzero(&sock_addr, sizeof(sock_addr));
   sock_addr.sin_family = AF_INET;
   sock_addr.sin_port = htons(SERVER_PORT);
   inet_pton(AF_INET, argv[1], &sock_addr.sin_addr);

 //  printf("%d\n",sockaddr.sin_addr.s_addr & 0x000000FF);
 //  printf("%d\n",(sockaddr.sin_addr.s_addr>> 8) & 0x000000FF);
 //  printf("%d\n",(sockaddr.sin_addr.s_addr>> 16) & 0x000000FF);
 //  printf("%d\n",(sockaddr.sin_addr.s_addr>>24) & 0x000000FF);


 //printf("XXXX = %d ", sizeof(message));

 #if 1

    /*Connect to server */
    int t = connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
 if(t < 0)
 	{
 	 printf("errono - %d %s \n", errno, strerror(errno));
	 
 	}

// printf("T = %d\n",t);

  //   printf("%d ", sizeof(message));
   /*send a message*/
   write(sockfd, (void *)&message, 6);

   int n = read(sockfd, &message,100);

   message[n] = '\0';
   
   
    printf("Received = %d  %s \n",n,message);

	

 
 
#endif
   



}
