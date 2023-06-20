/*
 * sysv_msgq_client.c
 *
 *  Created on: Jul 14, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/stat.h>
//#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct mymsg
{
	long type;
	char msg[10];
}MSG;



void main(int arg, char *argv[])
{
	printf("Hello world\n");

	int ret;
	int mgid = msgget(IPC_PRIVATE, IPC_CREAT | 0777);
	printf("msg id = %d \n", mgid);


	//
	/*Get the properties of mgid*/
	struct msqid_ds t;
	msgctl(mgid, IPC_STAT, &t);

	printf("MSGQBYTES = %d\n",t.msg_qbytes);


	int c = fork();
	if(c == 0)
	{
		printf("child\n");

		MSG m;
		m.type = 10;
		m.msg[0] = 'a';
		m.msg[1] = 'b';
		m.msg[2] = '\0';

		int msg_ret = msgsnd(mgid, &m, 3, IPC_NOWAIT);
		if(msg_ret < 0)
		{
			perror("MSGSND failed");
		}

	}
	else
	{
		printf("Parent\n");
		wait(&ret);
		MSG m;
		int msg_rec = msgrcv(mgid, &m, 3,0,0);
		if(msg_rec < 0)
		{
			perror("MSGRCV failed");
		}
		printf("Received message = %s\n", m.msg);

	}





}
