#include "stdio.h"
#include "fcntl.h" //file open close
#include "sys/types.h" // types
#include "sys/stat.h" //mkfifo - this is not used
#include "unistd.h"

int  main(void)
{
int fd;
char buf[250] = {0};
char *test ="/tmp/tempfifo";
fd = open(test, O_RDONLY | O_NONBLOCK);
read(fd, buf, 250);
printf("Read = %s\n",buf);
close(fd);
return 0;

}
