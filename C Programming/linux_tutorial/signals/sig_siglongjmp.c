/*
 * sig_siglongjmp.c
 *
 *  Created on: Jun 29, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<setjmp.h>
#include<signal.h>


sigjmp_buf s1;

void fun1()
{
	printf("Function 1");
	siglongjmp(s1,1); //This will restore the
}

void main(int argc, char *argv[])
{

	printf("Hello world\n");
	sigset_t new, bad;
	sigemptyset(&new);
	sigfillset(&new);
	sigfillset(&bad);

	sigprocmask(SIG_BLOCK,&new, &bad);

	switch(sigsetjmp(s1,1))
	{
	case 0:
		printf("This is the case 0\n");
		fun1();
		break;
	case 1:
		printf("Call is from sigjmp\n");
		break;
	}



}
