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
	struct sockaddr_in cli_soc_addr;
	char message[100] = "";
	int n = 0;


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
   /*Bind address*/
   bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

   /*listen*/
    listen(sockfd, 5);

   while(1)
   	{
     /*accept*/
	 int test = sizeof(struct sockaddr);
      int soc_acc = accept(sockfd,(struct sockaddr *)&cli_soc_addr, &test );
    if(soc_acc < 0)
 	{
 	 printf("Server accept errono - %d %s \n", soc_acc, strerror(errno));
	 exit(1);
	 
 	}
	//int c = fork();
	//if(c != 0)
		//{
		//close(soc_acc);
		//}
	//else
		{

		//close(sockfd);

   /*read*/
   n = read(soc_acc, (void *)&message, 100);
    if(n < 0)
 	{
 	 printf("Server errono - %d %s \n", errno, strerror(errno));
	 exit(1);
	 
 	}
   printf("server message length = %d ", n);

   message[n] = '\0';
   	printf("Server rcvd msg = %s \n",message);


	strcat(message,"-Sankar");

   /*write*/
   write(soc_acc,(void *)&message,13);



	
		}
   //strcat(message,"Sankar");

   /*write*/
  // write(soc_acc,)
   

   	}
   
   
   

 //  printf("%d\n",sockaddr.sin_addr.s_addr & 0x000000FF);
 //  printf("%d\n",(sockaddr.sin_addr.s_addr>> 8) & 0x000000FF);
 //  printf("%d\n",(sockaddr.sin_addr.s_addr>> 16) & 0x000000FF);
 //  printf("%d\n",(sockaddr.sin_addr.s_addr>>24) & 0x000000FF);


 printf("XXXX = %d ", sizeof(message));

 #if 0

    /*Connect to server */
    connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

     printf("%d ", sizeof(message));
   /*send a message*/
   write(sockfd, message, strlen(message));

   read(sockfd, message,100);
    printf("Received = %s \n",message);

 
 
#endif
   



}

