/*
 * fileoperations.c
 *
 *  Created on: Jun 22, 2016
 *      Author: sankarsa
 */


#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
//#include<sys/ioctl.h>
#include<linux/fs.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>


/*Open flags:
 * Flags:
 * O_CREAT					- Create if not exist..
 * O_SYNC 					- No buffering;
 * O_TRUNC 					- Delete the content and open the file;
 * 							  this is applicable only for regular files
 * O_WRONLY 				- Write only
 * O_RDONLY					- Read only
 * O_RDWR					- Read write
 * O_APPEND					- Open in append mode
 * O_DIRECTORY 				- If opened file is not a directory, this function fails.
 * 							  usage: Testing if it is a file or directory
 * O_EXCL					- This flag along with O_CREATE will ensure that file is created and
 * 							  open in this call. If file already exists, open fails. Also the symbolic
 * 							  links are not followed while opening.
 * O_NOFOLLOW				- If path is symbolic link, the open call fails.
 * O_CLOEXEC				- Close this descriptor when the process call exec() function to load another
 * 							  program.
 * O_TMPFILE				- Temporary file will be create on specified path. linkat() function can be used
 * 							  to convert this file to permanent one..
 *
 *
 *
 * Permission flags:
 * S_IRUSR 				- User have read permission
 * S_IWUSR 				- User have write permission
 * S_IXUSR 				- User have execute permission
 *
 * S_IRGRP	 			- Group have read permission
 * S_IWGRP 				- Group have write permission
 * S_IXGRP				- Group have execute permission
 *
 * S_IROTH 				- Others have read permission
 * S_IWOTH 				- Others have write permission
 * S_IXOTH 				- Others have execute permission
 *
 * S_IRWXG  			- Group have all permission
 * S_IRWXO				- others have all permission
 * S_IRWXU				- User have all permission
 *
 *
 * */



void main(int argc, char*argv[])
{
	

		//printf("%s\n", buffer);

		/*open file in */
		if(argc != 2)
		{
			return;
		}


		Writeoperation(argv);
		ReadOperation(argv);
		Seekoperation(argv);
		FileOpenwithflags(argv);



		IoctlOperation(argv);
		FileCntl(argv);

}

int Writeoperation(char *argv[])
{
		int filefd = -1;
		char buffer[ 5 * 1024 * 1024] = "Hello world is the first";

		/****************************************************
		 *			FILE OPEN operation						*
		****************************************************/
		/*
		 * O_CREATE  	- Creates the file, if not exists
		 * O_RDWR		- File in read write mode
		 *
		 * S_IROTH 		- Give others read only permission.
		 * */
		filefd = open(argv[1], O_CREAT | O_RDWR , S_IROTH);
		if(filefd < 0)
		{
			perror("Failed to open");
		}
		else
		{
			printf("File open fd = %d \n",filefd);
		}

		/*
		 * Write the data from buffer to file
		 *
		 * */

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
		/*
		 * Close the file
		 * */

		if(close(filefd) < 0)
		{
			perror("File close failed");
		}

}

void ReadOperation(char * argv[])
{

		int filefd = -1;
		char buffer[ 5 * 1024 * 1024] = "Hello world is the first";
		/*
		 * Open the file in read only mode..
		 * */
		filefd = open(argv[1],  O_RDONLY , S_IROTH);
		if(filefd < 0)
		{
			perror("Failed to open");
		}
		else
		{
			printf("File open fd = %d \n",filefd);
		}

		/*
		 * Read the data
		 * */
		memset(buffer,0, sizeof(buffer));
		int actual_read = read(filefd, buffer, 1024);
		buffer[actual_read] = '\0';
		printf("Read len = %d data = %s\n",actual_read  , buffer);

		/*
		 * Close the file
		 * */

		if(close(filefd) < 0)
		{
			perror("File close failed");
		}


}

void Seekoperation(char *argv[])
{

	int filefd = -1;
	char buffer[ 5 * 1024 * 1024] = "Hello world is the first";
	int actual_read = 0;

	/*
	 * Open the file in read only mode..
	 * */
	filefd = open(argv[1],  O_RDONLY , S_IROTH);
	if(filefd < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("File open fd = %d \n",filefd);
	}
	/*
	 * seek to offset of 10th and finding the data
	 * */
	printf("Lseek  = %d \n",lseek(filefd, 0, SEEK_CUR));
	if(lseek(filefd, 10, SEEK_SET) < 0)
	{
		perror("Lseek failed");
	}
	actual_read = read(filefd, buffer, 2);
	buffer[actual_read] = '\0';
	printf("Read len = %d data = %s\n",actual_read  , buffer);

	if(lseek(filefd, 0, SEEK_END) < 0)
	{
		perror("Lseek failed");
	}

	/*
	 * Getting the size of the file..
	 * */
	int size = 0;
	if((size = lseek(filefd, 0, SEEK_CUR)) < 0)
	{
				perror("Lseek failed");
	}
	else
	{
				printf("Size of file= %d \n",size);
	}

	/*
	 * Close the file
	 * */

	if(close(filefd) < 0)
	{
		perror("File close failed");
	}
}

void FileOpenwithflags(char *argv[])
{
	int filefd = -1;
	/*open a file with O_CREATE flag*/
	filefd = open(argv[1], O_CREAT | O_RDWR , S_IROTH);
	if(filefd < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("File open fd = %d \n",filefd);
	}


	/*Usage of O_EXCL.. this call always fails as the file in already created */
	if(open(argv[1], O_CREAT | O_RDWR | O_EXCL , S_IROTH) < 0)
	{
		perror("Failed to open");
	}

	/*O_DIRECTORY to check if the path is directory or not*/
	if(open(argv[1], O_DIRECTORY | O_RDWR , S_IROTH) < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("%s is a directory \n", argv[1]);
	}




	/*
	 * Close the file
	 * */

	if(close(filefd) < 0)
	{
		perror("File close failed");
	}




}

void IoctlOperation(char *argv[])
{
	int filefd = -1;
	/*open a file with O_CREATE flag*/
	filefd = open(argv[1], O_CREAT | O_RDWR , S_IROTH);
	if(filefd < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("File open fd = %d \n",filefd);
	}

	long attr = 0;


	if(ioctl(filefd, FS_IOC_GETFLAGS, &attr) < 0)
	{
		perror("IOCTL FAILED");
	}
	printf("Attribute = %x \n", attr);


	/*
	 * Close the file
	 * */

	if(close(filefd) < 0)
	{
		perror("File close failed");
	}

}


void FileCntl(char *argv[])
{

	int filefd = -1;
	int ret = -1;
	/*open a file with O_CREATE flag*/
	filefd = open(argv[1], O_CREAT | O_RDWR , S_IROTH);
	if(filefd < 0)
	{
		perror("Failed to open");
	}
	else
	{
		printf("File open fd = %d \n",filefd);
	}

	long attr = 0;

	attr = fcntl(filefd, F_GETFL);
	printf("The flag attribute is - %d \n",attr);
	attr |= O_APPEND;
	ret = fcntl(filefd, F_SETFL, attr);


	attr = fcntl(filefd, F_GETFL);
	printf("The flag attribute is[A] - %d \n",attr);


}







