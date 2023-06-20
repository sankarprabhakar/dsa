#include <stdio.h>
#include<fcntl.h>
#include<errno.h>

/*

1. ldd - can be used to list the dynamic dependency
2. strace - can be used to trace the system calls
3. ltrace - for tracing the library calls

*/

void main(void)
{

int fd = open("TT.txt",O_RDONLY);
if(fd == -1)
{
 perror("open"); //this function will print the error in user readable format
 printf("Error is - %s \n",strerror(errno)); //strerror() - This funciton will convert the error number to string....
 exit( 1);
}


}
