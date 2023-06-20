#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
{
int status = 0;

long flag = fcntl(1, F_GETFD);
flag |= FD_CLOEXEC;
fcntl(1,F_SETFD,flag); // The child proess do not have access to standard output


pid_t childpid = fork();
	if(childpid == 0)
	{
		printf("Hello from Child process pid = %d\n", (long)getpid());

int e =	execl("/media/sf_VM_share/tutorial/linux_tutorial/process/test.out","test.out","arg1","arg2",NULL);
perror("Execl failed");
printf("Execl ret value = %d \n",e);

		//exit(0);
	}
	else if(childpid == -1)
	{
		printf("Error in fork\n");
	}
	else
	{

	 printf("Hello from parent  process pid = %d\n", (long)getpid());

	 waitpid(childpid, &status, WUNTRACED);
	 	printf("Child return status = %d \n",WEXITSTATUS(status));
	}


}
