/*
 * sys_msgq_client1.c
 *
 *  Created on: Jul 14, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>


typedef struct mymsg
{
	long type;
	char msg[10];
}MSG;

void main(int argc, char *argv[])
{
	printf("Main\n");


	key_t key = ftok("/tmp/key1", 8);

	int mgid = msgget(key, IPC_CREAT | 0777);


	MSG t;

	/*Message 100*/
	t.type = 100;
	t.msg[0] = 'h';
	t.msg[1] = 'e';
	t.msg[2] = 'l';
	t.msg[3] = 'l';
	t.msg[4] = 'o';
	t.msg[5] = '\0';

	int ret =  msgsnd(mgid, &t, 6, 0);
	if(ret < 0)
	{
		perror("MSG SND ERROR");
	}

	/*Message 200*/
		t.type = 200;
		t.msg[0] = 'H';
		t.msg[1] = 'e';
		t.msg[2] = 'l';
		t.msg[3] = 'l';
		t.msg[4] = 'o';
		t.msg[5] = '\0';

		 ret =  msgsnd(mgid, &t, 6, 0);
		if(ret < 0)
		{
			perror("MSG SND ERROR");
		}

		/*Message 300*/
				t.type = 300;
				t.msg[0] = 'H';
				t.msg[1] = 'E';
				t.msg[2] = 'R';
				t.msg[3] = 'R';
				t.msg[4] = 'O';
				t.msg[5] = '\0';

				 ret =  msgsnd(mgid, &t, 6, 0);
				if(ret < 0)
				{
					perror("MSG SND ERROR");
				}


				/*Message 300*/
								t.type = 400;
								t.msg[0] = 'E';
								t.msg[1] = 'E';
								t.msg[2] = 'E';
								t.msg[3] = 'E';
								t.msg[4] = 'E';
								t.msg[5] = '\0';

								 ret =  msgsnd(mgid, &t, 6, 0);
								if(ret < 0)
								{
									perror("MSG SND ERROR");
								}






	//while(1)
		//;





}
