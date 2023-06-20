/*
 * sys_msgq_server1.c
 *
 *  Created on: Jul 14, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct mymsg
{
	long type;
	char msg[10];
}MSG;
void main(int argc, char*argv[])
{

	key_t key = ftok("/tmp/key1",8);
	int mgid = msgget(key, IPC_CREAT | 0777);
	MSG t ;
	int s = msgrcv(mgid, &t, 6, 200,0 );
	if(s < 0)
	{
		perror("RCV Error");
	}

	printf("The message = %s \n",t.msg);


	/*What if already 200 is taken and nonblocking*/
	s = msgrcv(mgid, &t, 6, 200,0 | IPC_NOWAIT );
	if(s < 0)
	{
		perror("RCV Error");
	}

	printf("The message = %s \n",t.msg);


	s = msgrcv(mgid, &t, 6, 100,0 );
	if(s < 0)
	{
		perror("RCV Error");
	}

	printf("The message = %s \n",t.msg);



	s = msgrcv(mgid, &t, 1, 300,0 ); //Error message...
	if(s < 0)
	{
		perror("RCV Error");
	}
	else
		printf("The message = %s \n",t.msg);


	s = msgrcv(mgid, &t, 2, 400, MSG_NOERROR ); //Error message... with
	if(s < 0)
	{
		perror("RCV Error");
	}
	else{
		t.msg[s] = '\0'; // as MSG_NOERROR is specified; atmax mess len is 2(parameter )..
		printf("The message = %s \n",t.msg);
	}

	/*Removing the message queue*/
	int ret = msgctl(mgid, IPC_RMID, NULL);
	if(ret < 0)
	{
		perror("Removed the queue");
	}
	/*Trying to check if the message queue is there?.. This will give error*/
	//key_t key = ftok("/tmp/key1",8);
		 mgid = msgget(key,  0777);
		if(mgid < 0)
			{
				perror(" MSG queue is not there");
			}









	/*Removing the message queue*/

	//while(1)
		//;


}
