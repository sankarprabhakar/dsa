/*
 * register_variables.c
 *
 *  Created on: Dec 8, 2016
 *      Author: sankarsa
 */


int test_register()
{
//	register static int a = 67; this will give compilation error.. multiple storage class

	volatile register int a = 90;//this is valid

	register int b= 60;
	//int *c = &b; -This gives error, as address of register variable is not accessbile

 int s = 90;
	register int *c; //this is valid , a register can hold the address of a variable.
	c = &s;

}



