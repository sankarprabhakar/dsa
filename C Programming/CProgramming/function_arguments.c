/*
 * function_arguments.c
 *
 *  Created on: Dec 6, 2016
 *      Author: sankarsa
 */

/*main function arg*/
void funarg_main()
{
	f1();
f2();
f3();
}

int f1()
{
printf("%d %s\n", __LINE__, __FUNCTION__);
}
int f2(void) /*void will prevent calls with */
{
	printf("%d %s\n", __LINE__, __FUNCTION__);
	}


int f3()
{
	f1("A","B");
	printf("%d %s\n", __LINE__, __FUNCTION__);
	//f2("A"); //If void is avoided in f2() definition then it wont give a compilation error
}
