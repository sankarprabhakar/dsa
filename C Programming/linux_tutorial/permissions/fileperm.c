/*
 * fileperm.c
 *
 *  Created on: Jul 4, 2016
 *      Author: sankarsa
 */
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(int argc, char*argv[])
{
	printf("Hello world\n");

	int ret = setreuid(-1,9001); // File created will have the user id as 9001
	if(ret < 0)
	{
		perror("Setreuid failed");
	}


	printf("GETUID UID = %d GID = %d \n", getuid(), getgid());
	printf("GETGID UID = %d GID = %d \n", geteuid(), getegid());
	int uid,gid,suid;
    ret = getresuid(&uid,&gid,&suid);
    if(ret < 0)
    {
    		perror("Getresuid failed");
    }


    printf("UID = %d GID = %d SUID = %d \n", uid, gid, suid);
	//umask of the process
	umask(S_IROTH | S_IWOTH | S_IXOTH | S_IRGRP | S_IWGRP | S_IXGRP); // file cannot have rwx for other and group

	int fd = open(argv[1], O_CREAT | O_RDONLY);//File created will have the useid as 9001
	if(fd < 0)
	{
		perror("Failed to open the file");
	}


}


int temp_change_privileage(int euid)
{

	int ret = seteuid(euid); // File created will have the user id as 9001
	if(ret < 0)
	{
		perror("Setreuid failed");
	}

}
