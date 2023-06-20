/*
 * dupoperation.c
 *
 *  Created on: Jun 23, 2016
 *      Author: sankarsa
 */


#include<unistd.h>
#include<fcntl.h>

/*All the printf's in this function will be written to a file, name of this file is passed
 * as argument to this executable
 * */
void main(int argc, char*argv[])
{
	//printf("%s\n", buffer);

	/*open file in */
	if(argc != 2)
	{
		return;
	}

	int filefd = -1;
	int newfd = -1;
	char buffer[ 5 * 1024 * 1024] = "Hello world is the first";

	filefd = open(argv[1], O_CREAT | O_RDWR , S_IROTH);
	if(filefd < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("File open fd = %d \n",filefd);
	}

	if(close(1)< 0)
	{
		perror("STD OUT close failed");
	}

	newfd = dup(filefd);
	printf("the new fd = %d \n",newfd);
	printf("This data is being written to some file named %s \n",argv[1]);


		/*writing using filefd*/
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


		if(close(1)< 0)
		{
			perror("STD OUT close failed");
		}

		printf("the new fd = %d \n",newfd);


		/*use of dup2*/
		newfd = dup2(filefd, 1);

		printf("Newly written data after dup2()\n");


		if(close(filefd)< 0)
		{
			perror("STD OUT close failed");
		}

}
