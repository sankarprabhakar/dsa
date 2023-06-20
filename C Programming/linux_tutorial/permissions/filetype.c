#include<stdio.h>
#include<sys/stat.h>

void printfiletype(mode_t mod);
void printtype(char *);
void main(int argc, char*argv[])
{
	printf("S_IFREG =  %x S_IFDIR = %x S_IFCHR = %x S_IFBLK = %x S_IFIFO = %x S_IFSOCK = %x S_IFLNK = %x\n",S_IFREG, S_IFDIR,S_IFCHR, S_IFBLK, S_IFIFO,S_IFSOCK,S_IFLNK);


	struct stat s1,s2,s3;
	int ret = -1;
	ret = stat("./test.txt", &s1);
	if(ret < 0)
	{
		perror("Stat failed");
	}
	printf("Mode =  %o\n", s1.st_mode);
	printfiletype(s1.st_mode);


	ret = stat("./test1", &s1);
	if(ret < 0)
	{
		perror("Stat failed");
	}
	printf("Mode =  %o\n", s1.st_mode);
	printfiletype(s1.st_mode);


	ret = lstat("/home/san/test1/tt", &s1);
	if(ret < 0)
	{
		perror("Stat failed");
	}
	printf("Mode =  %o\n", s1.st_mode);
	printfiletype(s1.st_mode);

	ret = stat("/dev/sda1", &s1);
	if(ret < 0)
	{
		perror("Stat failed");
	}
	printf("Mode =  %o\n", s1.st_mode);
	printfiletype(s1.st_mode);

	ret = stat("/dev/null", &s1);
	if(ret < 0)
	{
		perror("Stat failed");
	}
	printf("Mode =  %o\n", s1.st_mode);
	printfiletype(s1.st_mode);


	ret = lstat("test.txt", &s1);
		if(ret < 0)
		{
			perror("Stat failed");
		}
		printf("Mode =  %o\n", s1.st_mode);
		printfiletype(s1.st_mode);

printf("***********************************************\n");

printtype("test.txt");
printtype("./test1");
printtype("/home/san/test1/tt");
printtype("/dev/sda1");
printtype("/dev/null");

}

void printtype(char *filename)
{
	int ret;
	struct stat s1;
	ret = lstat(filename, &s1);
	if(ret < 0)
	{
		perror("Stat failed");
	}
	printf("Mode =  %o\n", s1.st_mode);
	printfiletype(s1.st_mode);
	if(S_ISLNK(s1.st_mode))
	{
		stat(filename,&s1);
			printf("linked to ");
			printfiletype(s1.st_mode);

	}
}




void printfiletype(mode_t mod)
{

	if(S_ISREG(mod))
	{
		printf("Regular file\n");
	}
	else if(S_ISDIR(mod))
	{
		printf("Directory\n");
	}
	else if(S_ISCHR(mod))
	{
		printf("character file\n");
	}
	else if(S_ISBLK(mod))
	{
		printf("Block file\n");
	}
	else if(S_ISFIFO(mod))
	{
		printf("fifo file\n");
	}
	else if(S_ISSOCK(mod))
	{
		printf("socket file\n");
	}
	else if(S_ISLNK(mod))
	{
		printf("Link file\n");
	}
}



