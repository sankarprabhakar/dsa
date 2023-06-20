/*
 * bufferedoperation.c
 *
 *  Created on: Jun 23, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc, char*argv[])
{

	char test[1025] = {0};

	/*
	 *
	 * C Library buffering
	 *
	 * */
/*
 * How to avoid buffering from C library. Setting Buffer to NULL
 * */

	setvbuf(stdin, NULL,_IONBF, 0);
	scanf("%s", &test);

	/*How to flush the C-library file*/
	fflush(stdin);



	/*
	 *
	 * LINUX Buffering
	 *
	 *
	 * */

	/*How to avoid buffering in system layer; Open file using O_SYNC operation*/

	int filefd = -1;
	char buffer[ 5 * 1024 * 1024] = "Hello world is the first";
	filefd = open(argv[1], O_CREAT | O_RDWR | O_SYNC , S_IROTH);
	if(filefd < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("File open fd = %d \n",filefd);
	}


//	char buffer[ 5 * 1024 * 1024] = "Hello world is the first";

	size_t len = strlen(buffer);
	size_t actual_written = 0, total_remaining = len;
	char *data = buffer;

	printf("Length of data to be written is %d\n", len);
	while(total_remaining > 0)
	{
		actual_written = write(filefd, data, total_remaining);
		printf("Actual written = %d\n", actual_written);
		data = data + actual_written;
		total_remaining = total_remaining-actual_written;
		printf("total_remaining = %d\n", total_remaining);

	}

	/*Other API's for sync*/
	/*
	 *sync();
	 *fsync(fd);
	 *fdatasync(fd);
	 *
	 */

	sync();
	fsync(filefd);
	fdatasync(filefd);



}
