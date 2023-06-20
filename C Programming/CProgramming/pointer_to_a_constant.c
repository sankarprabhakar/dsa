/*
 * pointer_to_a_constant.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */


/*point to a constanct = Pointer points to a constant, i.e value of constant
 * cannot be changed. But the value the pointer points to can be changed*/
#include<stdio.h>

void testing_pointer_to_a_const();

#if 0
void main()
{
	testing_pointer_to_a_const();
}
#endif

void testing_pointer_to_a_const()
{
	/*defining the pointer*/
	int const *p = NULL;
	const int x = 50;
	p = &x;

	//*p=89; //this should give a error;

	//constant can be assigned to normal pointer and the value can be changed.
	int *y = p;
	*y = 90;
	printf("C = %d",x); // this will print 90
}
