#include<stdio.h>

extern char ** environ;


int main()
{
// printf("PATH = %s",getenv("PATH"));
/* 
char pwd[150], path[150];
char *s =  getenv("PATH");
strcpy(path, s);
strcat(path,";");
s = getenv("PWD");
strcpy(pwd, s);
//printf("pwd = %s \n",pwd);
strcat(path,pwd);

setenv("PATH",path,1);
*/
char **c = environ;

//printf("%s\n",NULL);

for(; c != NULL && *c != NULL; c++)
{
   printf("%s\n",*c);
}




char *path = getenv("PATH");
char *pwd = getenv("PWD");

char f_path[200] = "PATH=";

//strncpy(f_path,"PATH=",6);
//printf("%s",f_path); 
strcat(f_path,path);
strcat(f_path,";");
strcat(f_path,pwd);

printf("goint ot set %s\n",f_path); 
putenv(f_path);

printf("PATH = %s\n",getenv("PATH"));

char l[50] = "Hello";
char r[50] = "Value";
setenv(l,r,1);
l[0] = 'A';
setenv(l,r,1);
c = environ;
unsetenv("Hello");
unsetenv("LANG");

//printf("%s\n",NULL);

for(; c != NULL && *c != NULL; c++)
{
   printf("%lu = %s\n",c, *c);
}


}
