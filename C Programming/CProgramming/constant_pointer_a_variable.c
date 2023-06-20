/*
 * constant_pointer_a_variable.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */

#if 0
void main()
{
	constant_pointer_to_a_variable();
}
#endif

void constant_pointer_to_a_variable()
{
		int a = 90;
		int  b = 30;
		int *const p = &a;  // pointer is constant.

		//p = &b; //This will give a error..

		*p = 100; //value of what it points to can be changed
		printf("a = %d \n",a);

}
