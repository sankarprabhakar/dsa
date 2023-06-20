#include<stdio.h>


int main(int argc, char *argv[])
{
int i= 0;
for( i = 0; i<argc;i++)
{
 printf("argv[%d] = %s \n",i,argv[i]);
}
printf("Print Env PARENT=%s\n",getenv("PARENT"));
printf("Hello worlds %s \n",getenv("PATH"));

}
