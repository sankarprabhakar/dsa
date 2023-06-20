#include "stdio.h"
#include "unistd.h"
#include "sys/stat.h"
//Global variable 
int g_var = 0;
#define __line__ __LINE__

void main()
{

	int c_pid = 0;
	int l_var = 5;
	l_var++;
	int ret;
	printf("GET PID parent = %d PPID = %d line = %d \n", getpid(),getppid(), __line__);

	c_pid = fork();
	//c_pid = fork();
	if(c_pid >= 0)
	{
		 if(c_pid == 0)
		 {

			 printf("GET Child PID  = %d PPID = %d line = %d \n", getpid(),getppid(), __line__);
			 g_var++;
			 l_var++;
			 printf("1 Global = %d Local = %d \n", g_var, l_var);
		 }
		 else
		 {

			 printf("GET PID  = %d  PPID = %d line = %d \n", getpid(),getppid(), __line__);
			 g_var += 10;
			 l_var += 20;
			 printf("2 Global = %d Local = %d \n", g_var, l_var);
			 //printf("");
			 printf("Ret status = %d ret = %d \n\n",wait(&ret), ret); // wait returns the pid of the process which got terminated
			 printf("Ret status = %d ret = %d \n\n",wait(&ret), ret); // wait returns -1, if no more child process is there to be terminated

		 }
	}
	else
	{
	 printf("Fork failed\n");
	}


}
