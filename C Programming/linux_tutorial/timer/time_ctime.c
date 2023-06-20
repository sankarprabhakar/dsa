#include<stdio.h>
#include<time.h>
#include<sys/time.h>


int main(int argc, char *argv[])
{

time_t x = 0;
struct timeval y;
gettimeofday(&y,NULL);

time_t t1 = time(NULL);

printf("T = %lu \n",t1);

//struct tm *t2 = localtime(t1);
//printf("Testint  = %d\n",t2->tm_sec);

//printf("%s \n",asctime(localtime(time(NULL))));


printf("second from 1970 = %d \n",y.tv_sec);
printf("ctime = %s ",ctime(&y.tv_sec));

//printf("");
printf("Hello world\n");

}
