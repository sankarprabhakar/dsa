/*
 * interview_variable_args.c
 *
 *  Created on: Jan 5, 2017
 *      Author: sankarsa
 */

#include<stdio.h>
#include<stdarg.h>
//int print_var_arg(int count, ...);
int print_var_arg(int count, ...);
main_vararg()
{
	test_vararg_q1();
}


test_vararg_q1()
{
	print_var_arg(6,2,1,2,3,4,5,6,.99,8.99);
}

int print_var_arg(int count, ...)
{
	va_list a;

	printf("count = %d \n", count);
	va_start(a,count);

	//min = va_arg(a,int);
	int i = 0;
	for(i = 1;i <= count; i++)
	{
		printf("%d\n",va_arg(a,int));
	}
	va_end(a);
}
