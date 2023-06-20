#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
 printf("Hello world!! \n\n");

int fd = open("t.txt", O_RDONLY);
if(fd < 0)
{
 printf("Error 1\n");
 return -1;
}
printf("FD at first open is = %d \n",fd);


int fd1 = open("t.txt", O_RDONLY);
if(fd1 < 0)
{
 printf("Error 1\n");
 return -1;
}

}
