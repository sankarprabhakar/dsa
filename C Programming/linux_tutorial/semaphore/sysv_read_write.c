/*
 * sysv_read_write.c
 *
 *  Created on: Jul 15, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/stat.h>

void writeOp(int semid);
void readOp(int semid);
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};
void main(int argc, char *argv[])
{
	printf("Hello world\n");
	key_t k = ftok("/tmp/sem2", 8);
	if(k <0)
	{
		perror("SEM open failed");
		return;
	}
	int semid = semget(k,2,IPC_CREAT|0777);
	if(semid < 0)
	{
		perror("SEM GET FAILED");
		return;
	}
	printf("semid = %d \n", semid);
	union semun s;
	/*Setting the value for the semaphore*/
		s.val = 0;
#if 0
		int ret = semctl(semid, 0/*semnum*/,SETVAL,s);
		if(ret < 0)
		{
			perror("SEMCTL ERROR");
			return;
		}
		s.val = 0;
				 ret = semctl(semid, 1/*semnum*/,SETVAL,s);
				if(ret < 0)
				{
					perror("SEMCTL ERROR");
					return;
				}

#endif
	//struct sembuf op[5];
	char o;
	while(1)
	{
		printf("Operation R/W?\n");
		scanf("%c%*[\n]", &o);
		fflush(stdin);
		fflush(stdout);
		if(o == 'R')
		{
			readOp(semid);
		}
		else if(o == 'W')
		{
			writeOp(semid);

		}
	}
}

void readOp(int semid)
{
	/*
	 * 1. wait till write sem is 0
	 * 2. take a read sem
	 * 3. Do opearition..
	 * 4. release the ream sem
	 * */

	 printsemval(semid);
	struct sembuf op[2];
	char o;
	op[0].sem_num = 0;
	op[0].sem_op = 0;
	op[0].sem_flg = 0;
	op[1].sem_num = 1;
	op[1].sem_op = 1;
	op[1].sem_flg = 0;


	int ret = semop(semid, op, 2);
	if(ret < 0)
	{
		perror("SEM OP ERROR");
		return;
	}
	 printsemval(semid);
	printf("Reading\n");

redo:
	printf("Stop reading Y/N ?\n");
	scanf("%c%*[\n]", &o);
	fflush(stdin);
	fflush(stdout);
	if(o == 'Y')
	{
		op[0].sem_num = 1;
		op[0].sem_op = -1;
		op[0].sem_flg = 0;
		int ret = semop(semid, op, 1);
		if(ret < 0)
		{
			perror("SEM OP ERROR");
			return;
		}
		printsemval(semid);
	}
	else {
		goto redo;
	}

}

void writeOp(int semid)
{
	/*
	 * 1. wait till write sem is 0
	 * 2. wait till read sem is 0
	 * 3. take the write sem..
	 * 3. Do opearition..
	 * 4. release the write sem
	 * */
	printsemval(semid);
	struct sembuf op[3];
	char o;
	op[0].sem_num = 0;
	op[0].sem_op = 0;
	op[0].sem_flg = 0;
	op[1].sem_num = 1;
	op[1].sem_op = 0;
	op[1].sem_flg = 0;
	op[2].sem_num = 0;
	op[2].sem_op = 1;
	op[2].sem_flg = 0;



	int ret = semop(semid, op, 3);
	if(ret < 0)
	{
		perror("SEM OP ERROR");
		return;
	}
	printsemval(semid);
	printf("Writing\n");

redo:
	printf("Stop writing Y/N ?\n");
	scanf("%c%*[\n]", &o);
	fflush(stdin);
	fflush(stdout);
	if(o == 'Y')
	{
		op[0].sem_num = 0;
		op[0].sem_op = -1;
		op[0].sem_flg = 0;
		int ret = semop(semid, op, 1);
		if(ret < 0)
		{
			perror("SEM OP ERROR");
			return;
		}
		printsemval(semid);

	}
	else {
		goto redo;
	}

}
int printsemval(int semid)
{
	union semun s;
		/*Setting the value for the semaphore*/
			s.val = 0;
			int ret = semctl(semid, 0/*semnum*/,GETVAL,&s);
			if(ret < 0)
			{
				perror("SEMCTL ERROR");
				return;
			}
			else
				{
				printf("Sem val 0  = %d \n", s.val);
				}

			 ret = semctl(semid, 1/*semnum*/,GETVAL,&s);
						if(ret < 0)
						{
							perror("SEMCTL ERROR");
							return;
						}
						else
							{
							printf("Sem val 1 = %d \n", s.val);
							}

	}
