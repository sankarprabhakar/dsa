/*
 * pointer_arithmatic.c
 *
 *  Created on: Aug 16, 2018
 *      Author: prabhaka
 */


void pointer_main()
{
	pointer_q3();

}

int pointer_q1()
{
	int j[] = {89,90};
	int *p = &j;
	int k = *p++;
	printf("p->[89,90] , *p++ = %d  *p=%d\n",k, *p);
}


int pointer_q2()
{
	int j[] = {89,90};
	int *p = &j;
	int k = *++p;
	printf("p->[89,90] *++p = %d\n",*p);
}

int pointer_q3()
{
	int j[] = {89,90};
	int *p = &j;
	int k = ++(*(++p));
	printf("p->[89,90] *++p = %d\n",k);
}
