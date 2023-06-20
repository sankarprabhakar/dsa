/*
 * atexit.c
 *
 *  Created on: Jun 27, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<stdlib.h>


void f1();
void f2();
void f3();
void f4();

void main(int argc, char *argv[])
{


	atexit(f1);
	atexit(f2);
	atexit(f3);
	atexit(f4);

}

void f1()
{
	printf("PSS -- %s\n", __FUNCTION__);

}
void f2()
{
	printf("PSS -- %s\n", __FUNCTION__);

}
void f3()
{
	printf("PSS -- %s\n", __FUNCTION__);
}
void f4()
{
	printf("PSS -- %s\n", __FUNCTION__);
}
