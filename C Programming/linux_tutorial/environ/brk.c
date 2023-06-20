/*
 * brk.c
 *
 *  Created on: Jun 25, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/resource.h>


void main(int argc, char *argv[])
{
	struct rlimit r;


	printf("%x\n",sbrk(0)); // returns the current data pointer
	printf("%x\n",sbrk(4)); // inc the prg brk by 4 and return old pointer
	printf("%x\n",sbrk(4));
	printf("%x\n",sbrk(4));


	printf("%x\n",getrlimit(RLIMIT_DATA, &r));
	printf("cur = %x\n",r.rlim_cur);
	printf("max = %x\n",r.rlim_max);
	printf("%x\n",getrlimit(RLIMIT_STACK, &r));
	printf("cur = %x\n",r.rlim_cur);
	printf("max = %x\n",r.rlim_max);



}
