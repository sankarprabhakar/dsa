/*
 * constant_pointer_to_constant_variable.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */

void const_pointer_to_const_variable();
#if 0
void main()
{
	const_pointer_to_const_variable();
}
#endif

void const_pointer_to_const_variable()
{
	// pointer & variable is also constant..
	const int a = 80;
	int b = 90;
	const int * const p = &b;

	//*p = 600;
	//p = &b;
	//*p = 80;
}


