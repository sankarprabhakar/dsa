/*
 * cheggi.c
 *
 *  Created on: 21-Jun-2017
 *      Author: sansaras
 */


test_cheg1()
{

int local = 1001, copy = 0, number;
number = local;

int array[] = {0,1,2};

char *s = "Hello";
printf("Avinob told this %s \n",s);
//printf("%d \n", **array+10);
		  while(local != 0)
{
	copy = copy *10;
	copy = copy + local %10;
	local = local/10;
}
if(number == copy)
{
	printf("1----");
}
else
	printf("2");


}
