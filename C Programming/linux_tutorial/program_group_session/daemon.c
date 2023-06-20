/*
 * daemon.c
 *
 *  Created on: Jul 4, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<unistd.h>



void main(int argc, char *argv[])
{

	printf("Max open descriptors = %d\n", sysconf(_SC_OPEN_MAX));

	/*
	 * 1. Fork
	 * 2. make a new session using setsid() --> This process is session leader
	 * 3. Fork --> get rid of session leader -->
	 * 4. Set umask
	 *
	 * 5. chnange home directory
	 *
	 * */

	int c = fork();
	if(c>0)
	{
		return;
	}
	else if(c < 0)
	{
		printf("Fork failed \n");
	}

	int ret = setsid();
	if(ret < 0)
	{
		perror("SETSID ERROR");
	}

	c = fork();

	if(c>0)
	{
			return;
	}
	else if(c < 0)
	{
			printf("Fork failed \n");
	}
	/*This wont be the session leader*/

	umask(0);
	chdir("/");

	while(1)
		;

}
