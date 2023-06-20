/*
 * bool.c
 *
 *  Created on: Dec 7, 2016
 *      Author: sankarsa
 */

#include<stdbool.h> //From C99 standard

main_test_bool()
{
	test_bool();
	test_char_arithmetic();
	compare_two_floats();
}


void test_bool()
{
	bool x = false;
	printf("Value of true = %d x = %d ",true, x);
}


void test_char_arithmetic()
{

	char a = 0xfb;
	unsigned char b= 0xfb;
	printf("%c %c",a,b);

	if(a == b)
	{
		printf("same\n");
	}
	else
	{
		//if(b == a)
		printf("A and b are different %d %d\n",a,b);
	}
	/*before comparison both a and b are converted to integers*/

	char x1 = 20;
	char x2 = 30;
	char x3 = (x1 * x2)/6;

	printf("X 3 = %d \n",x3); // all arithm metic operation happens after conversion to integer.


	int c =0xfb;
	unsigned int d = 0xfb;
	if(c == d)
		{
			printf("same\n");
		}
		else
		{
			//if(b == a)
			printf("A and b are different\n");
		}
}

compare_two_floats()
{
	float a = 0.1;

	if(a == 0.1)
	{
		printf("A is 0.1");
	}
	else if (a == 0.1f)
	{
		printf("A is 0.1f");
	}
	else
	{
		printf("A is 0.1 or 0.1F");
	}
}
