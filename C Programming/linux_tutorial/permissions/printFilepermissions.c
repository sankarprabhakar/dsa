

#include<sys/stat.h>


char perm[] = {'d','r','w','x','r','w','x','r','w','x','\0'};

char a_perm[10] = {};





void main(int argc, char *argv[])
{
	int ret = -1;
	struct stat s1;
	if(argc != 2)
	{
		return;
	}
	else
	{
		ret = lstat(argv[1], &s1);
		if(ret < 0)
		{
			perror("LSTAT failed");
		}
		else
		{
			printpermissioninformat(s1.st_mode);
		}
	}
}

void printpermissioninformat(mode_t x)
{
	if(S_ISDIR(x))
	{
		printf("d");
	}
	else
	{
		printf("-");
	}
	if(x & S_IRUSR)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	if(x & S_IWUSR)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	if(x & S_IXUSR)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}

	if(x & S_IRGRP)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	if(x & S_IWGRP)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	if(x & S_IXGRP)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}


	if(x & S_IROTH)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	if(x & S_IWOTH)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	if(x & S_IXOTH)
	{
		printf("x\n");
	}
	else
	{
		printf("-\n");
	}

}

