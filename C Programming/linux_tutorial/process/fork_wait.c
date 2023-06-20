#include<stdio.h>
//#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int func(int num)
{
return num * num;
}

void main()
{
int ret  = 0;

pid_t childpid = fork();
if(childpid == 0)
{
printf("Hello from Child process pid = %d\n", (long)getpid());
sleep(4);
exit(func(2));

}
else if(childpid == -1)
{
 printf("Error in fork\n");
}
else
{
 
 printf("Hello from parent process pid = %d\n", (long)getpid());
}

wait(&ret);
printf("Value returned by child= %d \n", (ret>>8)&0xff);
}
