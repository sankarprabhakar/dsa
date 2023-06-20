/*
 * inputoutput.c
 *
 *  Created on: Mar 6, 2017
 *      Author: sankarsa
 */


 #define _GNU_SOURCE

#include<stdio.h>

void inputoutput()
{
	char b[3] = {'\0'};
	char in = {'c'};
	int a[3] = {'\0'};

	//char *c = NULL;
	int len = 0;

  //  printf("%d",stdin);
	//getline(&c,&len, stdin);




	char c,d,e;
	int f[4];

	printf("%p %p %p\n", b,&in,a);
	printf("%p %p %p %p %p %p %p\n", &c,&d,&e, &f,&f[1], &b,&a);
	fun11();

	//printf("Address frmae = %p  %p\n",__builtin_frame_address(1),__builtin_frame_address(0) );
//	printf("enter something \n");

//	gets(&in);
	//printf("%s \n",in);
//	printf("%s \n",a);


}

fun11()
{
	static int b = 55;
	int a = 0;
	printf("fun11 a = %p \n", &a);
//	char a[1*1024*1024 + (98*1024*1024)/100] = {0};
	fun22();
}
fun22()
{
	static int b = 65;
	int a = 0;
		printf("fun22 a = %p \n", &a);
	//char a[1*1024*1024] = {0};
fun33();
}

fun33()
{
	int a = 0;
		printf("fun33 a = %p \n", &a);
	printf("frame address of cur fun = %p \n",__builtin_frame_address(0));
	printf("frame address of  fun2 = %p \n",__builtin_frame_address(1));
	printf("frame address of  fun1 = %p \n",__builtin_frame_address(2));
	printf("frame address of  inpout = %p \n",__builtin_frame_address(3));
}
