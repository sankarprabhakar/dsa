#include <stdio.h>
#include "sys/stat.h"// mkno, mkfifo etc..
#include "fcntl.h"//file operations
#include "sys/types.h"//pthread_* types
#include "unistd.h" //read write etc...
int  main(void)
{
    int fd;
    char *fifo = "/tmp/tempfifo";
    mkfifo(fifo, 0666);
    fd = open(fifo, O_WRONLY | O_NONBLOCK);
    write(fd, "Makkry", sizeof("Makkry"));
printf("PSS - written\n");
    write(fd, "Makkry-2", sizeof("Makkry"));
    close(fd);
printf("closed\n");
//unlink(fifo);
return 0;
}

