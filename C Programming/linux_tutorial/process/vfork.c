#include<stdio.h>
//#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int idata = 111;

void main()
{

int istack = 222;
pid_t childpid = vfork();
if(childpid == 0)
{
istack *=3;
idata *=3;
 printf("Hello from Child process pid = %d\n", (long)getpid());
exit(0);
}
else if(childpid == -1)
{
 printf("Error in fork\n");
}
else
{
  printf("Hello from parent process pid = %d\n", (long)getpid());
}
printf("PID = %d(%s) istack = %d idata = %d\n", (long)getpid(),(childpid==0)?"child":"Parent",istack,idata);
}
