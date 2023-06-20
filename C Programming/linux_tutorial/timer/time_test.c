#include<stdio.h>
#include<sys/time.h>

struct timeval val;

int main()
{

int ret = gettimeofday(&val,NULL);
if(ret == -1)
{
 printf("Error \n");
 return -1;
}

printf("time = %d & %d \n",val.tv_sec,val.tv_usec);


printf("Time elapsed since epoch = %d\n",time(NULL));



 printf("Hello wat man \n");
}
