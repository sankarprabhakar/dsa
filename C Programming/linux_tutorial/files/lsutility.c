#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
void main(int argc, char *argv[])
{
	char path[1024] = ".";

	DIR *dp = NULL;
	//parse argv..
	int len = strlen(argv[1]);
	printf("len = %d \n",len);

	struct dirent *temp = NULL;

	int filefd = open(argv[1], O_RDONLY | O_DIRECTORY);
	if(filefd < 0)
	{
		perror("Filefd is a file");
	}
	else
	{
		dp = opendir(argv[1]);
		if(dp < 0)
		{
			perror("Not directory");
		}
		else
		{
			while((temp = readdir(dp) ) != NULL)
			{
				printf("Name = %s size = %d\n", temp->d_name);
				struct stat buf;
				stat(temp->d_name,&buf);
				printf("%d",buf.st_gid);
			}
		}
	}
}
