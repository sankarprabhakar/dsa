#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
{
int status = 0, ret = 0;
char *path = getenv("PATH");
char *pwd = getenv("PWD");

char f_path[250] = "PATH=";

//strncpy(f_path,"PATH=",6);
//printf("%s",f_path);
strcat(f_path,path);
strcat(f_path,":");
strcat(f_path,pwd);

printf("goint ot set %s\n",f_path);
putenv(f_path);
printf("PATH = ",getenv("PATH"));
pid_t childpid = fork();
char *param[]={"test","arg1","arg2",NULL};
if(childpid == 0)
{

printf("Hello from Child process pid = %d\n", (long)getpid());

ret = execv("/media/sf_VM_share/tutorial/linux_tutorial/process/test.out",param);
if(ret == -1)
{
 printf("Error \n");
}
else
{
 printf("ret = %d \n",ret);
}
exit(0);
}
else if(childpid == -1)
{
 printf("Error in fork\n");
}
else
{
 
 printf("Hello from parent  process pid = %d\n", (long)getpid());
}
waitpid(childpid, &status, WUNTRACED);
}
