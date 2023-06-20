#include<stdio.h>
#include<setjmp.h>

jmp_buf buf1;

typedef char chat[2];


//jmp_buf buf1;
void main(int argc, char *argv[])
{
	int ret = setjmp(buf1);/*This call will store the stack..*/

	chat x = {'2','3'};
	if(ret == 1)
	{
		printf("returned from f1()\n");
		fun2();
	}
	else if(ret == 2)
	{
		printf("returned from f1()\n");
		exit(0);
	}
	fun1();
	return;
}


void fun1()
{
	printf("This is from fun1\n");
	longjmp(buf1, 1);
}

void fun2()
{
	printf("This is from fun2\n");
	longjmp(buf1, 2);
}

